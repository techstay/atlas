# %%
import sqlalchemy
from sqlalchemy import Column, Integer, Sequence, String, create_engine, text
from sqlalchemy.orm import aliased, declarative_base, sessionmaker

sqlalchemy.__version__

# %%

# Connecting databases
engine = create_engine("sqlite:///:memory:", echo=True)

# Setting up mappings
Base = declarative_base()


class User(Base):
    __tablename__ = "users"
    id = Column(Integer, Sequence("user_id_seq"), primary_key=True)
    username = Column(String(64))
    nickname = Column(String(128))
    password = Column(String(32))

    def __repr__(self):
        return f"User(id={self.id}, name={self.username}, nickname={self.nickname}, password={self.password})"


Base.metadata.create_all(engine)


Session = sessionmaker(bind=engine)
session = Session()

user1 = User(username="yitian", nickname="易天", password="123456")
session.add(user1)

session.query(User).filter_by(username="yitian").first()

# %%
# Adding multiple objects
session.add_all(
    [
        User(username="zhang3", nickname="张三", password="123456"),
        User(username="li4", nickname="李四", password="123456"),
        User(username="lily", nickname="李丽", password="00000000"),
        User(username="fakeuser", nickname="假的", password="fffffffack"),
    ]
)
session.commit()

# %%
# Transactions
user1.password = "12345678"  # type: ignore
print(session.dirty)

print(session.query(User).filter_by(username="yitian").first())
session.rollback()

print(session.query(User).filter_by(username="yitian").first())


# %%
# Deleting objects
fakeuser = session.query(User).filter_by(username="fakeuser").first()
print(
    "删除前的fake用户:{0}".format(
        session.query(User).filter_by(username="fakeuser").count()
    )
)
session.delete(fakeuser)
print(
    "删除后的fake用户:{0}".format(
        session.query(User).filter_by(username="fakeuser").count()
    )
)

# %%
# Querying objects
instance = session.query(User).all()[0]
print(instance)
print(type(instance))

userInfoTuple = session.query(
    User.id, User.username, User.nickname, User.password
).all()[0]
id1, username1, nickname1, password1 = userInfoTuple
print(userInfoTuple)
print(type(userInfoTuple))

# Custom column names
userInfoTuple = session.query(User.username.label("name"), User.nickname).all()[0]
print(userInfoTuple.name, userInfoTuple.nickname)

# Querying with aliases

user_alias = aliased(User, name="user_alias")
user = session.query(user_alias, user_alias.username).all()[0]
print(user)

# Slicing queries
print([u for u in session.query(User).order_by(User.id)[2:4]])

# Filtering queries

# filter_by
for (name,) in session.query(User.username).filter_by(username="zhang3"):
    print(name)

# filter
for user in session.query(User).filter(User.username == "zhang3"):
    print(user)
# %%

# Native SQL queries
user1 = session.query(User).filter(text("username='zhang3'")).one()
print(user1)

# Binding parameters
for user in (
    session.query(User).filter(text("username like :name")).params(name="zhang3")
):
    print(user)

# %%
# Complete SQL statements
for user in (
    session.query(User)
    .from_statement(text("SELECT * from users where username like :name"))  # type: ignore
    .params(name="%i%")
):
    print(user)

# %%
