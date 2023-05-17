{-------------------------------------
 Resolução da lista 2
 Lucas Pessoa Oliveira Alves
--------------------------------------}

module Lista where
import Data.Char

--Exercício 1
converte :: Char -> (Char, Char, Int)  
converte x
    | isAlpha x = (toLower x, toUpper x, ord x)
    | otherwise = ('e','e',-1)

--Exercício 2

--Exercício 3
analisaLetra :: Char -> (Char, Char, Int)
analisaLetra x 
    | isAlpha x && x == toUpper x = (toUpper x, toLower x, ord x)
    | isAlpha x && x == toLower x = (toLower x, toUpper x, ord x)
    | otherwise = ('0','0',-1)

    