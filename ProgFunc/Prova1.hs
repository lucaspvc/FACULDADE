import Data.Char

type Acervo = [(Isbn, Titulo, Reserva, Volumes)]
type Emprestimo = [(Matricula, Isbn)]
type Isbn = Int
type Volumes = Int
type Titulo = String
type Matricula = String
type Reserva = Bool

acervo :: [(Isbn, Titulo, Reserva, Volumes)]
acervo = [(1,"AA", False, 3), (2,"BB", True, 4)]

emprestimo :: [(Matricula, Isbn)]
emprestimo = [("aaa1",1), ("aaa2",1)]

-- 1)O campo Reserva, do acervo, é True quando o livro é reservado ao uso exclusivo na biblioteca. Então, um livro só pode
-- ser emprestado caso esse campo seja False. Sabendo disso, faça uma solução em Haskell, chamada por func_1, que receba
-- um Isbn e o acervo e, em seguida, informe se o livro para tal Isbn pode ser emprestado (True) ou não (Not).
func_1 :: Isbn -> Acervo -> Bool
func_1 _ [] = False
func_1 isbn ((x,_,r,_):xs)
    | isbn == x = not (r)
    | otherwise = func_1 isbn xs 

myfunc_1:: Isbn -> Acervo -> Bool
myfunc_1 _ [] = False
myfunc_1 x (a:b)
    | x == (primeiro a) && (not(terceiro a)) = True
    | otherwise = myfunc_1 x b
    where
        primeiro (p,_,_,_) = p
        terceiro (_,_,t,_) = t

--2)Faça uma solução em Haskell chamada func_2 que receba um Isbn e informe quantos volumes daquele livro estão emprestado
func_2::Isbn -> Emprestimo -> Int
func_2 _ [] = 0
func_2 x ((m,i):xs)
    | x == i = 1 + func_2 x xs
    | otherwise = func_2 x xs

myfunc_2::Isbn -> Emprestimo -> Int
myfunc_2 _ [] = 0
myfunc_2 x (y:ys)
    | x == (snd y) = 1 + myfunc_2 x ys
    | otherwise = myfunc_2 x ys

--3)Faça uma solução em Haskell, chamada func_3 que receba um Isbn e retorne quantos livros há no acervo
func_3:: Isbn -> Acervo -> Int
func_3 _ [] = 0
func_3 isbn ((i,_,_,v):xs)
    | isbn == i = v
    | otherwise = func_3 isbn xs

myfunc_3 :: Isbn -> Acervo -> Int
myfunc_3 _ [] = 0
myfunc_3 isbn (x:xs)
    | isbn == primeiro x = quarto x
    | otherwise = myfunc_3 isbn xs
    where
        primeiro (a,_,_,_) = a
        quarto (_,_,_,b) = b

--4)Faça uma solução em Haskell, chamada func_4 que receba um Isbn e retorne a quantidade de livros disponível 
-- para empréstimo. Para tanto, deve-se observar os três pontos: a) quanto livros você tem no acervo; b) quantos estão 
--emprestado; c) se Reserva, retorne zero.
func_4 :: Isbn -> Int
func_4 isbn
    | func_1 isbn acervo = func_3 isbn acervo - func_2 isbn emprestimo
    | otherwise = 0

--5) Faça uma solução em Haskell, chamada func_5 que receba uma matrícula e um Isbn e, em seguida, retorne a lista de
--empréstimo atualizada. Caso o livro não possa ser emprestado (reservado ou sem disponibilidade), deve retornar a lista
-- de empréstimo sem alterações.
func_5 :: Matricula -> Isbn -> Emprestimo
func_5 matricula isbn
    | func_4 isbn == 0 = emprestimo
    | otherwise = (matricula,isbn):emprestimo