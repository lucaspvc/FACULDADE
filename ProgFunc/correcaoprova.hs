import Data.Char

type Acervo = [(Isbn, Titulo, Reserva, Volumes)]
type Emprestimo = [(Matricula, Isbn)]
type Isbn = Int             --Isbn de um livro
type Volumes = Int          --quantidade no acervo
type Titulo = String        -- titulo do livro
type Matricula = String     -- matrícula do discente
type Reserva = Bool         -- deve permanecer na biblioteca?


acervo ::[(Isbn, Titulo, Reserva, Volumes)]
emprestimo ::[(Matricula, Isbn)]

func_1::Isbn->Acervo->Bool
func_1 _ [] = False
func_1 isbn ((a,_,r,_):x)
    | a == isbn = not (r)
    | otherwise = func_1 isbn x
--Pode ser implementado assim
f1::Isbn->Acervo->Bool
f1 _ [] = False
f1 isbn (y:x)
    |(a==isbn) = not(r)
    |otherwise = f1 isbn x
    where (a,_,r,_) = y

func_2::Isbn->Emprestimo->Int
func_2 _ [] = 0
func_2 isbn ((m,i):x)
    |i == isbn = 1 + func_2 isbn x
    |otherwise = 0 + func_2 isbn x

func_3::Isbn->Acervo->Int
func_3 _ [] = 0
func_3 isbn ((i,_,_,v):x)
    |isbn == i = v 
    |otherwise = func_3 isbn x
    
func_4::Isbn->Int
func_4 isbn
    |func_1 isbn acervo = func_3 isbn acervo - func_2 isbn emprestimo
    |otherwise = 0

func_5::Matricula->Isbn->Emprestimo
func_5 matricula isbn
    |func_4 isbn == 0 = emprestimo
    |otherwise = (matricula,isbn):emprestimo --ou [(matricula,isbn)]++emprestimo