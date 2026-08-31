import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree, export_text
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

base = pd.read_csv("titanic completo.csv")
print(base.head())
print("\nDimensão da base:")
print(base.shape)
print("\nAtributos:")
print(base.columns)
print("\nValores ausentes:")
print(base.isnull().sum())

Y = base["survived"]
X = base.drop(columns=["survived"])


print("\nTipos dos atributos:")
print(X.dtypes)
print("\nQuantidade de valores distintos:")
print(X.nunique())


colunas_remover = [
    "name",
    "ticket",
    "cabin",
    "boat",
    "body",
    "home.dest"
]

X =X.drop(
    columns=colunas_remover,
    errors="ignore"
)

colunas_numericas = X.select_dtypes(
    include=["int64", "float64"]
).columns

for coluna in colunas_numericas:
    X[coluna] = X[coluna].fillna(
        X[coluna].median()
    )


colunas_categoricas = X.select_dtypes(
    include=["object"]
).columns

for coluna in colunas_categoricas:
    X[coluna] = X[coluna].fillna(
        X[coluna].mode()[0]
    )


X =pd.get_dummies(
    X,
    columns=colunas_categoricas,
    dtype=int
)


print("\nBase após codificação:")
print(X.head())



X_treino, X_teste, y_treino, y_teste = train_test_split(
    X,
    Y,
    test_size=0.20,
    random_state=42
)

print("\nTreino:", X_treino.shape)
print("Teste:", X_teste.shape)



arvore =DecisionTreeClassifier(
    criterion="entropy",
    random_state=42
)

arvore.fit(
    X_treino,
    y_treino
)



previsoes =arvore.predict(X_teste)

acuracia= accuracy_score(
    y_teste,
    previsoes
)

print(
    f"\nAcurácia: {acuracia:.2%}"
)



cm =confusion_matrix(
    y_teste,
    previsoes
)

print("\nMatriz de confusão:")
print(cm)


print("\nRelatório de classificação:")
print(
    classification_report(
        y_teste,
        previsoes,
        target_names=[
            "Morreu",
            "Sobreviveu"
        ]
    )
)


plt.figure(
    figsize=(25,15)
)

plot_tree(
    arvore,
    feature_names=X.columns,
    class_names=[
        "Morreu",
        "Sobreviveu"
    ],
    filled=True,
    rounded=True,
    fontsize=8
)

plt.title(
    "Árvore de DecisãoTitanic"
)
plt.tight_layout()
plt.show()


print("\n" + "="*70)
print("REGRAS DA ÁRVORE")
print("="*70)

regras = export_text(
    arvore,
    feature_names=list(X.columns)
)

print(regras)


importancias =pd.DataFrame({
    "Atributo": X.columns,
    "Importância": arvore.feature_importances_})

importancias=importancias.sort_values(
    by="Importância",
    ascending=False
)

print("\nImportância dos atributos:")
print(
    importancias.to_string(index=False)
)