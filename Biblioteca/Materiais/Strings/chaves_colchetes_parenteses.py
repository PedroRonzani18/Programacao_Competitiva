# Descricao: Funcao que verifica se uma string contendo chaves, colchetes e parenteses esta balanceada.
def balanced(string) -> bool:
   stack = []
  
   for i in string:
       if i in '([{': stack.append(i)
          
       elif i in ')]}':
           if (not stack) or ((stack[-1],i) not in [('(',')'), ('[',']'), ('{','}')]):
               return False
           else:
               stack.pop()
      
   return not stack
