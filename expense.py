import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("Monthly_expenses.csv")

#BAR CHART: Expenses for each Month
plt.figure(figsize=(10,5))
plt.bar(df["Month"], df["Expense"], color='skyblue')
plt.title("Monthly Expenses")
plt.xlabel("Month")
plt.ylabel("Expense (Rs.)")
plt.grid(axis='y')
plt.show()

#PIE CHART: Expense percent of every month
plt.figure(figsize=(6,6))
plt.pie(df["Expense"], labels=df["Month"], autopct="%1.1f%%")
plt.title("Expense Share by each Month")
plt.show()