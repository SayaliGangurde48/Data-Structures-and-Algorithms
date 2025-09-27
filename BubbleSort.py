import pandas as pd

# Read Excel file
df = pd.read_excel("students.xlsx")

# Bubble Sort on Marks
n = len(df)
for i in range(n):
    for j in range(0, n-i-1):
        if df.loc[j, "Marks"] > df.loc[j+1, "Marks"]:
            # Swap entire rows
            df.iloc[[j, j+1]] = df.iloc[[j+1, j]].values

# Save sorted Excel file
df.to_excel("students_sorted_bubble.xlsx", index=False)

print("Bubble Sort complete! Check students_sorted_bubble.xlsx")
