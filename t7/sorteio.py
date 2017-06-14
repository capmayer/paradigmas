import tkinter as tk
import random

class Application(tk.Frame):
    done = True
    random_numbers = []

    def __init__(self, master=None):
        super().__init__(master)
        master.geometry("250x350")
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.logo_label = tk.Label(self, text="LOGO HERE")
        self.logo_label.pack()
        self.participants_label = tk.Label(self, text="Participantes: ")
        self.participants_label.pack()
        self.sort_input = tk.Entry(self)
        self.sort_input.pack()
        self.reset_button = tk.Button(self, text="Reset", command=self.reset_cb)
        self.reset_button.pack()
        self.winner_label = tk.Label(self, text="Winner's number")
        self.winner_label.pack()
        self.winner_num_label = tk.Label(self, text="Sorted number")
        self.winner_num_label.pack()
        self.sort_button = tk.Button(self, text="Sortear", command=self.sort_cb)
        self.sort_button.pack()


    def sort_cb(self):
        if(self.sort_input.get()):
            if not(self.random_numbers) and self.done:
                self.random_numbers = [x+1 for x in range(int(self.sort_input.get()))]
                random.shuffle(self.random_numbers)
                self.done = False
            if (self.random_numbers):
                random_index = random.randrange(0, len(self.random_numbers))
                self.winner_label["text"] = int(self.sort_input.get()) - len(self.random_numbers) + 1, "Ganhador(a)"
                self.winner_num_label["text"] = self.random_numbers.pop(random_index)
            else:
                print("It's over!!!!!")
                print("Restart to continue")
        else:
            print("No participants")

    def reset_cb(self):
        self.done = True
        self.random_numbers = []
        self.sort_input.delete(0, len(self.sort_input.get()))
        self.winner_label["text"] = "Winner's number"
        self.winner_num_label["text"] = "Sorted number"

root = tk.Tk()
app = Application(master=root)
app.mainloop()
