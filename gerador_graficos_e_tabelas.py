import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("resultados.csv")

algoritmos = df["algoritmo"].unique()

# ---------- Tabelas (uma por algoritmo, salvas em CSV separado) ----------
for alg in algoritmos:
    tabela = df[df["algoritmo"] == alg][["n", "tempo_medio_s", "comparacoes", "atribuicoes"]]
    tabela.to_csv(f"tabela_{alg}.csv", index=False)
    print(f"\nTabela - {alg}")
    print(tabela.to_string(index=False))

# ---------- Grafico 1: Tempo medio x n (todos os algoritmos juntos) ----------
plt.figure()
for alg in algoritmos:
    dados = df[df["algoritmo"] == alg]
    plt.plot(dados["n"], dados["tempo_medio_s"], marker="o", label=alg)
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo medio (s)")
plt.title("Tempo medio de execucao - Pior Caso")
plt.legend()
plt.grid(True)
plt.savefig("grafico_tempo.png")

# ---------- Grafico 2: Comparacoes x n ----------
plt.figure()
for alg in algoritmos:
    dados = df[df["algoritmo"] == alg]
    plt.plot(dados["n"], dados["comparacoes"], marker="o", label=alg)
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Numero de comparacoes")
plt.title("Comparacoes - Pior Caso")
plt.legend()
plt.grid(True)
plt.savefig("grafico_comparacoes.png")

# ---------- Grafico 3: Atribuicoes x n ----------
plt.figure()
for alg in algoritmos:
    dados = df[df["algoritmo"] == alg]
    plt.plot(dados["n"], dados["atribuicoes"], marker="o", label=alg)
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Numero de atribuicoes")
plt.title("Atribuicoes - Pior Caso")
plt.legend()
plt.grid(True)
plt.savefig("grafico_atribuicoes.png")

print("\nGraficos salvos: grafico_tempo.png, grafico_comparacoes.png, grafico_atribuicoes.png")
