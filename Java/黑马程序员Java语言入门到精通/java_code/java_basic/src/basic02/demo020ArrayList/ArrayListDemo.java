// ArrayList集合的长度不同于数组，可以发生改变
// 对于ArrayList来说， 有一个<E>表示泛型， 表示装载集合当中的所有元素， 全部是统一的类型
// 注意：泛型只能是引用类型， 不能是基本类型
// 如果希望向ArrayList中添加基本数据类型，必须使用基本类型对应的“包装类”, 包装类都位于java.lang包下
// | 基本类型 | 包装类(引用类型， 包装类都位于java.lang下) |
//| -------- | ------------------------------------------ |
//| byte     | Byte                                       |
//| short    | Short                                      |
//| int      | Integer                                    |
//| long     | Long                                       |
//| float    | Float                                      |
//| double   | Double                                     |
//| char     | Character                                  |
//| boolean  | Boolean                                    |
// 对于ArrayList， 直接打印得到的不是地址值，是内容, (toString)
// 对于ArrayList来说，add动作一定成功，返回值可用可不用，对于其他集合，add动作不一定成功
package basic02.demo020ArrayList;

import java.util.ArrayList;

public class ArrayListDemo
{
    public static void main(String[] args)
    {
        // ArrayList<String> strList = new ArrayList<String>();
        // 从jdk1.7开始，右边的尖括号内的内容可以省略不写，但尖括号要写
        ArrayList<String> strList = new ArrayList<>();

        System.out.println(strList); // []

        // add方法添加数据
        strList.add("World");
        strList.add("Hello");
        boolean success = strList.add("Java");
        System.out.println("Successfully added element: " + success);
        System.out.println(strList);

        // 遍历ArrayList
        // 输入strList.fori就能自动补全for遍历
        for (int i = 0; i < strList.size(); i++)
        {
            System.out.println(strList.get(i));
        }

        // get()获取元素
        String ele = strList.get(1);
        System.out.println(ele);

        // remove()删除元素
        String removedEle = strList.remove(1);
        System.out.println(removedEle + " was deleted");
        System.out.println(strList);

        // size()获取长度
        System.out.println("size: " + strList.size());

        // ArrayList<int> intList = new ArrayList<int>(); // 错误， 泛型只能是引用类型，不能是基本数据类型
        ArrayList<Integer> intList = new ArrayList<>();
        intList.add(12);
    }
}
