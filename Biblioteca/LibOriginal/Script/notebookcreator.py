import os
import subprocess
import shutil


def cpy_template():
    shutil.copyfile('template.tex', 'notebook.tex')


def get_blocked():
    blocked = set()
    with open("block_from_notebook.txt") as f:
        for line in f:
            # Remove comments
            line = line.split('#')[0]
            # Normalize filename
            line = line.strip().lower().replace(" ", "_") + ".cpp"
            blocked.add(line)
    return blocked


def remove_aux():
    items = [
        'notebook.aux',
        'notebook.log',
        'notebook.toc',
        'notebook.tex',
        'texput.log',
    ]
    for item in items:
        if os.path.exists(item):
            os.remove(item)


def get_dir():
    path = '../Materiais'
    section_list = os.listdir(path)
    section_list.sort()
    pre_list = ['Utils', 'Informações']
    complete_list = pre_list
    for sel in section_list:
        if sel not in pre_list:
            complete_list.append(sel)
    complete_list.remove('Outros')
    complete_list.append('Outros')
    section = []
    for section_name in complete_list:
        subsection = []
        section_path = os.path.join(path, section_name)
        items = os.listdir(section_path)
        for file_name in items:
            if file_name.endswith(('.cpp', '.py', '.sh', '.java')) or file_name.find('makefile') != -1:
                subsection.append(file_name)
            elif(os.path.isdir(os.path.join(section_path, file_name))):
                sub_files = os.listdir(os.path.join(section_path, file_name))
                subsection.extend([
                    os.path.join(file_name, name) 
                    for name in sub_files #if (name.endswith('.cpp', '.py', '.sh', '.java') or name.find('makefile') != -1)
                ])
        subsection.sort()
        section.append((section_name, subsection))
    return section


def create_notebook(section, blocked):
    path = '../Materiais'
    aux = ''
    with open('notebook.tex', 'a') as texfile:

        for (item, subsection) in section:
            aux += '\\section{%s}\n' % item
            for file in subsection:
                if(file in blocked):
                    continue

                name, ext = os.path.splitext(file)
                name = ' - '.join([part.replace('_', ' ').title() for part in name.split('/')])
                file_name = name
                nomes_separados = name.split("/")
                if(len(nomes_separados) > 1):
                    name = nomes_separados[0].capitalize()
                    for i in range(1, len(nomes_separados)):
                        name += " - " + nomes_separados[i].capitalize()
                file_path = os.path.join(path, item, file).replace("\\","/")

                aux += '\\includes{%s}{%s}\n' % \
                    (file_name, file_path)

        aux += '\n\\end{multicols}\n\\end{document}\n'
        texfile.write(aux)

def main():
    cpy_template()
    section = get_dir()
    blocked = get_blocked()
    create_notebook(section, blocked)

    cmd = ['pdflatex', '-interaction=nonstopmode', '-halt-on-error',
           'notebook.tex']
    with open(os.devnull, 'w') as DEVNULL:
        try:
            subprocess.check_call(cmd, stdout=DEVNULL)
            subprocess.check_call(cmd, stdout=DEVNULL)
        except Exception:
            print("Erro na transformação de LaTex para pdf.")
            print("Execute manualmente para entender o erro:")
            print('pdflatex -interaction=nonstopmode -halt-on-error notebook.tex')
            exit(1)

    remove_aux()

    print("O PDF foi gerado com sucesso!")

if __name__ == '__main__':
    main()