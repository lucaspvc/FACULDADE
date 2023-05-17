{-------------------------------------
 Resolução da lista 2
 Lucas Pessoa Oliveira Alves
--------------------------------------}

module Lista where
import Data.Char
{- Cabeçalho
minimun -> Retorna o menor valor Int de uma lista
ex: minimun [5,2,6,1,6,7,4] = 1

maximun -> Retorna o maior valor Int de uma lista
ex: maximun [5,1,6,4,3,9,5,6] = 9

min -> retorna o menor valor entre 2 argumentos
ex: min 1 7 = 1

max -> retorna o maior valor entre 2 argumentos
ex: max 8 14 = 14

where -> É uma palavra-chave usada para dividir a lógica ou cálculo mais complexo 
em partes menores, o que torna a lógica ou o cálculo fácil de entender e manusear


-}
--Exercício 1
converte :: Char -> (Char, Char, Int)  
converte x
    | isAlpha x = (toLower x, toUpper x, ord x)
    | otherwise = ('e','e',-1)

--Exercício 2
--a)
type Pessoa = (String, Int, Char)

pessoa :: Int -> Pessoa
pessoa rg
    |rg == 1 = ("Joao Silva", 12, 'm')
    |rg == 2 = ("Jonas Souza", 51, 'm')
    |rg == 3 = ("Jocileide Strauss", 21, 'f')
    |otherwise = ("Nao ha ninguem mais", 9999, 'x')

menor :: (String, Int, Char) -> (String, Int, Char) -> (String, Int, Char)
menor t1 t2 
    | (segundo t1) <= (segundo t2) = t1
    | otherwise = t2
    where
        segundo (_, x, _) = x


--Exercício 3
analisaLetra :: Char -> (Char, Char, Int)
analisaLetra x 
    | isAlpha x && x == toUpper x = (toUpper x, toLower x, ord x)
    | isAlpha x && x == toLower x = (toLower x, toUpper x, ord x)
    | otherwise = ('0','0',-1)


--Exercício 4
ordena :: Int -> Int -> Int -> Int -> (Int, Int, Int, Int)
ordena a b c d = (menor, segundoMenor, segundoMaior, maior)
  where
    menor = minimum [a, b, c, d]
    maior = maximum [a, b, c, d]
    segundoMenor = min (max a b) (max c d)
    segundoMaior = max (min a b) (min c d)
