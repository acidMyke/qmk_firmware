/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix driver configuration */
#    define RGB_MATRIX_LED_COUNT 72

#    define SPI_SCK_PIN A5
#    define SPI_MISO_PIN A6
#    define SPI_MOSI_PIN A7

#    define SNLED27351_SELECT_PINS \
        { B9, B8 }
#    define SNLED27351_SPI_DIVISOR 16
#    define SPI_DRIVER SPID1

/* Scan phase of led driver set as SNLED27351_SCAN_PHASE_9_CHANNEL(defined as 0x03 in snled27351.h) */
#    define PHASE_CHANNEL SNLED27351_SCAN_PHASE_9_CHANNEL

/* Set LED driver current */
#    define SNLED27351_CURRENT_TUNE \
        { 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40 }



/* Indications */
#    define CAPS_LOCK_INDEX 32
#    define LOW_BAT_IND_INDEX \
        { 65 }

#endif
