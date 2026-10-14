import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer 
from sklearn.preprocessing import OneHotEncoder

data=pd.read_csv("titanic.csv")
data["Embarked"]=data["Embarked"].replace({"S":1,"C":2,"Q":3})
print(data.head(3))
print(data.info())


# Tạo đặc trưng mới là cột Họ hàng
data["Family_size"]=(data["Parch"]+data["SibSp"])+1

# Lựa chọn đặc trưng
x=data.drop(columns=["PassengerId","Survived","Cabin","Ticket","Parch","SibSp","Name"])
y=data["Survived"]

# Phân tách tập dữ liệu
x_train,x_test,y_train,y_test=train_test_split(x,y,train_size=0.8,test_size=0.2,random_state=42)


x_train = x_train.reset_index(drop=True)
x_test = x_test.reset_index(drop=True)
y_train = y_train.reset_index(drop=True)
y_test = y_test.reset_index(drop=True)



# Xử lí dữ liệu thiếu
imputer=SimpleImputer(strategy="median")
x_train[["Age","Fare"]]=imputer.fit_transform(x_train[["Age","Fare"]])
x_test[["Age","Fare"]]=imputer.transform(x_test[["Age","Fare"]])

imputer2=SimpleImputer(strategy="most_frequent")
x_train[["Embarked"]]=imputer2.fit_transform(x_train[["Embarked"]])
x_test[["Embarked"]]=imputer2.transform(x_test[["Embarked"]])

# Mã hoá sang số cột Sex(giới tính)
ohe=OneHotEncoder(sparse_output=False)
train_column=ohe.fit_transform(x_train[["Sex"]])
train_column_new=pd.DataFrame(train_column,columns=ohe.get_feature_names_out(["Sex"]))

test_column=ohe.transform(x_test[["Sex"]])
test_column_new=pd.DataFrame(test_column,columns=ohe.get_feature_names_out(["Sex"]))

x_train=pd.concat([x_train.drop(columns=["Sex"]),train_column_new],axis=1) 
x_test=pd.concat([x_test.drop(columns=["Sex"]),test_column_new],axis=1)

print(x_train.head())


#Huấn luyện mô hình
model=LogisticRegression(random_state=1)
model.fit(x_train,y_train)
y_predict=model.predict(x_test.head(50))
print("Bảng so sánh:")
print(pd.DataFrame({"y_test":y_test.head(50),"y_predict":y_predict}))

a=model.score(x_test,y_test)
print(a)









