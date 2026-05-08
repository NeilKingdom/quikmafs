#ifndef TRIG_H
#define TRIG_H

#include "qm_common.h"

/**
 * @brief Converts degrees to radians.
 * @since 30-09-2024
 * @param[in] deg An angle given in degrees
 * @returns The conversion of angle __deg__ to radians
 */
static inline f32 qm_deg_to_rad(const f32 deg) {
    return deg * (qm_pi / 180.0f);
}

/**
 * @brief Converts radians to degrees.
 * @since 30-09-2024
 * @param[in] rad An angle given in radians
 * @returns The conversion of angle __rad__ to degrees
 */
static inline f32 qm_rad_to_deg(const f32 rad) {
    return rad * (180.0f / qm_pi);
}

#endif
