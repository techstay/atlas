# %%
import random
from pprint import pprint

from faker import Faker
from faker.providers import BaseProvider

fake = Faker("zh_CN")

names = [fake.name() for _ in range(10)]
pprint(names)


# %%
# custom providers
class Provider(BaseProvider):
    def random_hello(self):
        return random.choice(["hello", "hi"])


fake.add_provider(Provider)
fake.random_hello()


# %%
def generate_user():
    return {
        "name": fake.name(),
        "password": fake.password(length=10),
        "company": fake.company(),
        "job": fake.job(),
        "birthday": fake.date_of_birth(minimum_age=24, maximum_age=65).strftime(
            "%Y-%m-%d"
        ),
        "telephone": fake.phone_number(),
        "address": fake.address(),
    }


users = [generate_user() for _ in range(5)]

pprint(users)

# %%
