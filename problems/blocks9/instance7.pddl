

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on-table b1)
(on b2 b8)
(on b3 b7)
(on-table b4)
(on-table b5)
(on-table b6)
(on-table b7)
(on b8 b9)
(on b9 b6)
(clear b1)
(clear b2)
(clear b3)
(clear b4)
(clear b5)
)
(:goal
(and
(on b1 b9)
(on b4 b2)
(on b5 b1)
(on b6 b5)
(on b8 b4))
)
)


