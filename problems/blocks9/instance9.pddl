

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on b1 b4)
(on b2 b7)
(on-table b3)
(on-table b4)
(on-table b5)
(on b6 b3)
(on-table b7)
(on b8 b9)
(on b9 b1)
(clear b2)
(clear b5)
(clear b6)
(clear b8)
)
(:goal
(and
(on b2 b7)
(on b4 b9)
(on b6 b3)
(on b9 b1))
)
)


