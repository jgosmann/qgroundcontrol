// MESSAGE HUCH_FORCE_SENSORS PACKING

#define MAVLINK_MSG_ID_HUCH_FORCE_SENSORS 232

typedef struct __mavlink_huch_force_sensors_t
{
 uint64_t usec; ///< timestamp in microseconds
 uint16_t flex; ///< Flex sensor value
 uint16_t force; ///< Flexiforce force sensor
 uint16_t fsr; ///< FSR force sensor
} mavlink_huch_force_sensors_t;

#define MAVLINK_MSG_ID_HUCH_FORCE_SENSORS_LEN 14
#define MAVLINK_MSG_ID_232_LEN 14



#define MAVLINK_MESSAGE_INFO_HUCH_FORCE_SENSORS { \
	"HUCH_FORCE_SENSORS", \
	4, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_huch_force_sensors_t, usec) }, \
         { "flex", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_huch_force_sensors_t, flex) }, \
         { "force", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_huch_force_sensors_t, force) }, \
         { "fsr", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_huch_force_sensors_t, fsr) }, \
         } \
}


/**
 * @brief Pack a huch_force_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec timestamp in microseconds
 * @param flex Flex sensor value
 * @param force Flexiforce force sensor
 * @param fsr FSR force sensor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_force_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, uint16_t flex, uint16_t force, uint16_t fsr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[14];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint16_t(buf, 8, flex);
	_mav_put_uint16_t(buf, 10, force);
	_mav_put_uint16_t(buf, 12, fsr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 14);
#else
	mavlink_huch_force_sensors_t packet;
	packet.usec = usec;
	packet.flex = flex;
	packet.force = force;
	packet.fsr = fsr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 14);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_FORCE_SENSORS;
	return mavlink_finalize_message(msg, system_id, component_id, 14, 239);
}

/**
 * @brief Pack a huch_force_sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec timestamp in microseconds
 * @param flex Flex sensor value
 * @param force Flexiforce force sensor
 * @param fsr FSR force sensor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_force_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint16_t flex,uint16_t force,uint16_t fsr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[14];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint16_t(buf, 8, flex);
	_mav_put_uint16_t(buf, 10, force);
	_mav_put_uint16_t(buf, 12, fsr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 14);
#else
	mavlink_huch_force_sensors_t packet;
	packet.usec = usec;
	packet.flex = flex;
	packet.force = force;
	packet.fsr = fsr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 14);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_FORCE_SENSORS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 14, 239);
}

/**
 * @brief Encode a huch_force_sensors struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_force_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_force_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_force_sensors_t* huch_force_sensors)
{
	return mavlink_msg_huch_force_sensors_pack(system_id, component_id, msg, huch_force_sensors->usec, huch_force_sensors->flex, huch_force_sensors->force, huch_force_sensors->fsr);
}

/**
 * @brief Send a huch_force_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param usec timestamp in microseconds
 * @param flex Flex sensor value
 * @param force Flexiforce force sensor
 * @param fsr FSR force sensor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_force_sensors_send(mavlink_channel_t chan, uint64_t usec, uint16_t flex, uint16_t force, uint16_t fsr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[14];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint16_t(buf, 8, flex);
	_mav_put_uint16_t(buf, 10, force);
	_mav_put_uint16_t(buf, 12, fsr);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_FORCE_SENSORS, buf, 14, 239);
#else
	mavlink_huch_force_sensors_t packet;
	packet.usec = usec;
	packet.flex = flex;
	packet.force = force;
	packet.fsr = fsr;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_FORCE_SENSORS, (const char *)&packet, 14, 239);
#endif
}

#endif

// MESSAGE HUCH_FORCE_SENSORS UNPACKING


/**
 * @brief Get field usec from huch_force_sensors message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_force_sensors_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field flex from huch_force_sensors message
 *
 * @return Flex sensor value
 */
static inline uint16_t mavlink_msg_huch_force_sensors_get_flex(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field force from huch_force_sensors message
 *
 * @return Flexiforce force sensor
 */
static inline uint16_t mavlink_msg_huch_force_sensors_get_force(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field fsr from huch_force_sensors message
 *
 * @return FSR force sensor
 */
static inline uint16_t mavlink_msg_huch_force_sensors_get_fsr(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Decode a huch_force_sensors message into a struct
 *
 * @param msg The message to decode
 * @param huch_force_sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_force_sensors_decode(const mavlink_message_t* msg, mavlink_huch_force_sensors_t* huch_force_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP
	huch_force_sensors->usec = mavlink_msg_huch_force_sensors_get_usec(msg);
	huch_force_sensors->flex = mavlink_msg_huch_force_sensors_get_flex(msg);
	huch_force_sensors->force = mavlink_msg_huch_force_sensors_get_force(msg);
	huch_force_sensors->fsr = mavlink_msg_huch_force_sensors_get_fsr(msg);
#else
	memcpy(huch_force_sensors, _MAV_PAYLOAD(msg), 14);
#endif
}
