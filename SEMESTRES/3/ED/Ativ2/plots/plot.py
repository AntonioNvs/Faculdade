import pandas as pd
import matplotlib.pyplot as plt
import matplotlib as mpl

mpl.style.use(['ggplot']) 

def generate_plots(filename: str, operation: str):
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
            plt.title(f"Tempo de {info[measure]} para {operation} {info[op]}")
            plt.xlabel("Valor de N")
            plt.ylabel("Segundos")
            plt.savefig(f"plots/{operation.lower()}_{op}_{measure}.png")
            plt.clf()
    
def get_mean_time(filename: str, col: str):
    df = pd.read_csv(filename, index_col=0)

    print(df[col].mean())

if __name__ == "__main__":
    generate_plots("plots/fibonacci.csv", "Fibonacci")
