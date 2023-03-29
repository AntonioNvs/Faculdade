import pandas as pd
import matplotlib.pyplot as plt
import matplotlib as mpl

mpl.style.use(['ggplot']) 

def generate_plots(filename: str):
    df = pd.read_csv(filename, index_col=0)

    info = {
        "rec": "recursivo",
        "ite": "iterativo",
        "clock": "relógio",
        "user": "usuário",
        "sys": "sistema"
    }

    for op in ["rec", "ite"]:
        for measure in ["user", "sys", "clock"]:
            plt.plot(df.index, df[f"{op}_{measure}"])
            plt.title(f"Tempo de {info[measure]} para Fibonacci {info[op]}")
            plt.xlabel("Valor de N")
            plt.ylabel("Segundos")
            plt.savefig(f"plots/fib_{op}_{measure}.png")
            plt.clf()
    

if __name__ == "__main__":
    generate_plots("fibonacci.csv")
