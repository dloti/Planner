

(define (problem BW-rand-8)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 )
(:init
(arm-empty)
(on b1 b3)
(on-table b2)
(on b3 b4)
(on-table b4)
(on-table b5)
(on b6 b5)
(on b7 b1)
(on b8 b7)
(clear b2)
(clear b6)
(clear b8)
)
(:goal
(and
(on b1 b7)
(on b2 b3)
(on b6 b2)
(on b7 b4)
(on b8 b5))
)
)


