

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on b1 b7)
(on-table b2)
(on b3 b8)
(on b4 b5)
(on b5 b3)
(on b6 b2)
(on b7 b4)
(on b8 b6)
(on-table b9)
(clear b1)
(clear b9)
)
(:goal
(and
(on b1 b5)
(on b4 b8)
(on b5 b3)
(on b6 b1)
(on b7 b9))
)
)


