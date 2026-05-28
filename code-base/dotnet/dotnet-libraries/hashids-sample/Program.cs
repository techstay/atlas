// 项目没有输出，使用调试功能来查看每个函数的结果
using HashidsNet;

var salt = "this is a salt.";
var hashids = new Hashids(salt);

// int id
var hash = hashids.Encode(100);
var id = hashids.Decode(hash)[0];

// 加密long id
hash = hashids.EncodeLong(1000L);
var id2 = hashids.DecodeLong(hash)[0];

// 加密多个ID，不会轻易的被猜出
hash = hashids.Encode(1, 1, 1, 1, 1);
var ids = hashids.Decode(hash);

// 加密16进制字符串
hash = hashids.EncodeHex("cafe");
var hex = hashids.DecodeHex(hash);

// 指定哈希最短长度
hashids = new Hashids(salt, 8);
hash = hashids.Encode(100);
id = hashids.Decode(hash)[0];

// 指定哈希字符串要使用的字符
hashids = new Hashids(salt, 0, "ABCDEFGabcdefg1234567890");
hash = hashids.Encode(100);
ids = hashids.Decode(hash);
