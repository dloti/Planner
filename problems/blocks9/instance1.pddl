

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on-table b1)
(on-table b2)
(on b3 b4)
(on b4 b1)
(on b5 b9)
(on b6 b5)
(on b7 b8)
(on b8 b2)
(on-table b9)
(clear b3)
(clear b6)
(clear b7)
)
(:goal
(and
(on b1 b5)
(on b2 b9)
(on b3 b6)
(on b4 b7)
(on b6 b8)
(on b7 b3)
(on b9 b1))
)
)


