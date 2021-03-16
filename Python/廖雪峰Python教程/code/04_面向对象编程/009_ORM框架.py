# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

# Field类, 保存数据库表的字段名和字段类型
class Field(object):
    def __init__(self, name, column_type):
        self.name = name
        self.column_type = column_type

    def __str__(self):
        return "<%s:%s>" % (self.__class__.__name__, self.name)


# 各种类型的Field
class IntegerField(Field):
    def __init__(self, name):
        super(IntegerField, self).__init__(name, "bigint")


class StringField(Field):
    def __init__(self, name):
        super(StringField, self).__init__(name, "varchar(100)")


# model 的metaclass
class ModelMetaclass(type):
    def __new__(mcs, name, bases, attrs):
        if "Model" == name:
            return type.__new__(mcs, name, bases, attrs)
        print("Found model %s" % name)
        mappings = dict()

        for key, value in attrs.items():
            if isinstance(value, Field):
                print("Found mapping: %s => %s" % (key, value))
                mappings[key] = value
        for key in mappings.keys():
            attrs.pop(key)

        attrs["__mappings__"] = mappings  # 保存属性和列表的映射关系
        attrs["__table__"] = name  # 假设表名和类名一致
        return type.__new__(mcs, name, bases, attrs)


# 基类model
class Model(dict, metaclass=ModelMetaclass):
    def __int__(self, **kwargs):
        super(Model, self).__init__(**kwargs)

    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"Model object has no attribute: %s" % key)

    def __setattr__(self, key, value):
        self[key] = value

    def save(self):
        fields = []
        params = []
        args = []
        for key, value in self.__mappings__.items():
            fields.append(value.name)
            params.append('?')
            args.append(getattr(self, key, None))
        sql = "Insert into %s (%s) values %s" % (self.__table__, ','.join(fields), ','.join(params))
        print("SQL: %s" % sql)
        print("args: %s", str(args))


# ~~~~~~~~~~~~~Test code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class User(Model):
    # 定义类的属性到列的映射：
    id = IntegerField('id')
    name = StringField('username')
    email = StringField('email')
    password = StringField('password')


if "__main__" == __name__:
    # 创建一个实例：
    u = User(id=12345, name='Michael', email='test@orm.org', password='my-pwd')
    # 保存到数据库：
    u.save()
