

(define (problem BW-rand-10)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 )
(:init
(arm-empty)
(on-table b1)
(on-table b2)
(on b3 b10)
(on b4 b2)
(on-table b5)
(on b6 b4)
(on b7 b9)
(on-table b8)
(on b9 b8)
(on b10 b6)
(clear b1)
(clear b3)
(clear b5)
(clear b7)
)
(:goal
(and
(on b1 b8)
(on b2 b1)
(on b3 b4)
(on b4 b9)
(on b5 b2)
(on b7 b10)
(on b9 b7))
)
)


