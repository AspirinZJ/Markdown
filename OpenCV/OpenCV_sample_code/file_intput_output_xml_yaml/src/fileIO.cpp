// Created by jackzhang on 2/26/21.
#include <opencv2/core.hpp>
#include <iostream>
#include <string>

static void help(char **av)
{
	std::cout << std::endl << av[0] << " shows the usage of the OpenCV serialization functionality.\n" << "usage: \n"
			  << av[0] << " outputfile.yml.gz\n"
			  << "The output file may be either XML (xml) or YAML (yml/yaml). You can even compress it by "
			  << "specifying this in its extension like xml.gz yaml.gz etc... \n"
			  << "With cv::FileStorage you can serialize objects in OpenCV by using the << and >> operators\n"
			  << "For example: - create a class and have it serialized\n"
			  << "             - use it to read and write matrices." << std::endl;
}

class MyData
{
public:
	MyData() : A(0), X(0), id() {}

	explicit MyData(int) : A(97), X(CV_PI), id("mydata1234") // explicit to avoid implicit conversion
	{}

	void write(cv::FileStorage &fs) const                        //Write serialization for this class
	{
		fs << "{" << "A" << A << "X" << X << "id" << id << "}";
	}

	void read(const cv::FileNode &node)                          //Read serialization for this class
	{
		A = (int) node["A"];
		X = (double) node["X"];
		id = (std::string) node["id"];
	}

public:   // Data Members
	int A;
	double X;
	std::string id;
};

//These write and read functions must be defined for the serialization in cv::FileStorage to work
static void write(cv::FileStorage &fs, const std::string &, const MyData &x)
{
	x.write(fs);
}

static void read(const cv::FileNode &node, MyData &x, const MyData &default_value = MyData())
{
	if (node.empty())
		x = default_value;
	else
		x.read(node);
}

// This function will print our custom class to the console
static std::ostream &operator<<(std::ostream &out, const MyData &m)
{
	out << "{ id = " << m.id << ", ";
	out << "X = " << m.X << ", ";
	out << "A = " << m.A << "}";
	return out;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		help(av);
		return 1;
	}

	std::string filename = av[1];

	{ //write
		cv::Mat R = cv::Mat_<uchar>::eye(3, 3),
				T = cv::Mat_<double>::zeros(3, 1);
		MyData m(1);
		cv::FileStorage fs(filename, cv::FileStorage::WRITE);
		// or:
		// cv::FileStorage fs;
		// fs.open(filename, cv::FileStorage::WRITE);
		fs << "iterationNr" << 100;
		fs << "strings" << "[";                              // text - string sequence
		fs << "image1.jpg" << "Awesomeness" << "../data/baboon.jpg";
		fs << "]";                                           // close sequence
		fs << "Mapping";                              // text - mapping
		fs << "{" << "One" << 1;
		fs << "Two" << 2 << "}";
		fs << "R" << R;                                      // cv::cv::Mat
		fs << "T" << T;
		fs << "MyData" << m;                                // your own data structures
		fs.release();                                       // explicit close
		std::cout << "Write Done." << std::endl;
	}

	{//read
		std::cout << std::endl << "Reading: " << std::endl;
		cv::FileStorage fs;
		fs.open(filename, cv::FileStorage::READ);
		int itNr;
		//fs["iterationNr"] >> itNr;
		itNr = (int) fs["iterationNr"];
		std::cout << itNr;
		if (!fs.isOpened())
		{
			std::cerr << "Failed to open " << filename << std::endl;
			help(av);
			return 1;
		}
		cv::FileNode n = fs["strings"];                         // Read string sequence - Get node
		if (n.type() != cv::FileNode::SEQ)
		{
			std::cerr << "strings is not a sequence! FAIL" << std::endl;
			return 1;
		}
		cv::FileNodeIterator it = n.begin(), it_end = n.end(); // Go through the node
		for (; it != it_end; ++it)
			std::cout << (std::string) *it << std::endl;
		n = fs["Mapping"];                                // Read mappings from a sequence
		std::cout << "Two  " << (int) (n["Two"]) << "; ";
		std::cout << "One  " << (int) (n["One"]) << std::endl << std::endl;
		MyData m;
		cv::Mat R, T;
		fs["R"] >> R;                                      // Read cv::cv::Mat
		fs["T"] >> T;
		fs["MyData"] >> m;                                 // Read your own structure_
		std::cout << std::endl
				  << "R = " << R << std::endl;
		std::cout << "T = " << T << std::endl << std::endl;
		std::cout << "MyData = " << std::endl << m << std::endl << std::endl;
		//Show default behavior for non existing nodes
		std::cout << "Attempt to read NonExisting (should initialize the data structure with its default).";
		fs["NonExisting"] >> m;
		std::cout << std::endl << "NonExisting = " << std::endl << m << std::endl;
	}
	std::cout << std::endl
			  << "Tip: Open up " << filename << " with a text editor to see the serialized data." << std::endl;
	return 0;
}
