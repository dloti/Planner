

(define (problem BW-rand-8)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 )
(:init
(arm-empty)
(on b1 b3)
(on b2 b8)
(on b3 b7)
(on b4 b1)
(on b5 b6)
(on-table b6)
(on b7 b5)
(on-table b8)
(clear b2)
(clear b4)
)
(:goal
(and
(on b1 b6)
(on b2 b1)
(on b3 b8)
(on b4 b7)
(on b6 b3)
(on b7 b5)
(on b8 b4))
)
)


