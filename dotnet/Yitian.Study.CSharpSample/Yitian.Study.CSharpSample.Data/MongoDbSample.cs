using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MongoDB.Bson;
using MongoDB.Driver;

namespace Yitian.Study.CSharpSample.Data
{
    internal static class MongoDbSample
    {
        public static void Sample()
        {
            var client = new MongoClient("mongodb://localhost:27017");
            var db = client.GetDatabase("hello");
            var user = db.GetCollection<BsonDocument>("user");
            user.InsertOne(new BsonDocument
            {
                {
                    "name", "yitian"
                },
                {
                    "_id", 1
                },
                {
                    "age", 25
                }
            });
            user.InsertOne(new BsonDocument
            {
                {
                    "name", "zhang3"
                },
                {
                    "_id", 2
                },
                {
                    "age", 26
                }
            });
            user.InsertOne(new BsonDocument
            {
                {
                    "name", "li4"
                },
                {
                    "_id", 3
                },
                {
                    "age", 24
                }
            });

            Console.WriteLine("查询单条数据");
            var filter = Builders<BsonDocument>.Filter.Eq("_id", 1);
            Console.WriteLine(
                user.Find(filter).First()
            );
            Console.WriteLine("更新用户姓名");
            user.FindOneAndUpdate(filter, Builders<BsonDocument>.Update.Set("name", "易天"));

            Console.WriteLine("条件查询大于25的");
            filter = Builders<BsonDocument>.Filter.Gte("age", 25);
            user.Find(filter).ToList().ForEach(e => Console.WriteLine(e));

            Console.WriteLine("所有数据");
            user.Find(new BsonDocument()).ToList().ForEach(e => Console.WriteLine(e));

            user.DeleteMany(new BsonDocument());
        }
    }
}