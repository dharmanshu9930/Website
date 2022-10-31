import numpy as np
import pandas as pd
da=pd.read_csv("diabetes.csv")
x=da.iloc[:,0:8]
x
y=da["BMI"]
y
import seaborn as sns
import matplotlib.pyplot as plt
sns.set(style="ticks",color_codes=True)
sns.pairplot(da)
plt.show()