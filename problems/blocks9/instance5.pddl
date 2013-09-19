

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on b1 b5)
(on b2 b7)
(on b3 b4)
(on b4 b8)
(on b5 b3)
(on b6 b9)
(on-table b7)
(on-table b8)
(on b9 b1)
(clear b2)
(clear b6)
)
(:goal
(and
(on b1 b3)
(on b2 b6)
(on b3 b5)
(on b4 b9)
(on b5 b2)
(on b7 b8)
(on b8 b1)
(on b9 b7))
)
)


