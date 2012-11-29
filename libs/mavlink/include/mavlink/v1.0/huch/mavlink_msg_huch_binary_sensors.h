// MESSAGE HUCH_BINARY_SENSORS PACKING

#define MAVLINK_MSG_ID_HUCH_BINARY_SENSORS 231

typedef struct __mavlink_huch_binary_sensors_t
{
 uint64_t usec; ///< timestamp in microseconds
 uint8_t data; ///< Byte with each bit encoding one sensor value
} mavlink_huch_binary_sensors_t;

#define MAVLINK_MSG_ID_HUCH_BINARY_SENSORS_LEN 9
#define MAVLINK_MSG_ID_231_LEN 9



#define MAVLINK_MESSAGE_INFO_HUCH_BINARY_SENSORS { \
	"HUCH_BINARY_SENSORS", \
	2, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_huch_binary_sensors_t, usec) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_huch_binary_sensors_t, data) }, \
         } \
}


/**
 * @brief Pack a huch_binary_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec timestamp in microseconds
 * @param data Byte with each bit encoding one sensor value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_binary_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, uint8_t data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[9];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint8_t(buf, 8, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 9);
#else
	mavlink_huch_binary_sensors_t packet;
	packet.usec = usec;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 9);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_BINARY_SENSORS;
	return mavlink_finalize_message(msg, system_id, component_id, 9, 189);
}

/**
 * @brief Pack a huch_binary_sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec timestamp in microseconds
 * @param data Byte with each bit encoding one sensor value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_binary_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint8_t data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[9];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint8_t(buf, 8, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 9);
#else
	mavlink_huch_binary_sensors_t packet;
	packet.usec = usec;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 9);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_BINARY_SENSORS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 9, 189);
}

/**
 * @brief Encode a huch_binary_sensors struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_binary_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_binary_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_binary_sensors_t* huch_binary_sensors)
{
	return mavlink_msg_huch_binary_sensors_pack(system_id, component_id, msg, huch_binary_sensors->usec, huch_binary_sensors->data);
}

/**
 * @brief Send a huch_binary_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param usec timestamp in microseconds
 * @param data Byte with each bit encoding one sensor value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_binary_sensors_send(mavlink_channel_t chan, uint64_t usec, uint8_t data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[9];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint8_t(buf, 8, data);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_BINARY_SENSORS, buf, 9, 189);
#else
	mavlink_huch_binary_sensors_t packet;
	packet.usec = usec;
	packet.data = data;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_BINARY_SENSORS, (const char *)&packet, 9, 189);
#endif
}

#endif

// MESSAGE HUCH_BINARY_SENSORS UNPACKING


/**
 * @brief Get field usec from huch_binary_sensors message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_binary_sensors_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field data from huch_binary_sensors message
 *
 * @return Byte with each bit encoding one sensor value
 */
static inline uint8_t mavlink_msg_huch_binary_sensors_get_data(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a huch_binary_sensors message into a struct
 *
 * @param msg The message to decode
 * @param huch_binary_sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_binary_sensors_decode(const mavlink_message_t* msg, mavlink_huch_binary_sensors_t* huch_binary_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP
	huch_binary_sensors->usec = mavlink_msg_huch_binary_sensors_get_usec(msg);
	huch_binary_sensors->data = mavlink_msg_huch_binary_sensors_get_data(msg);
#else
	memcpy(huch_binary_sensors, _MAV_PAYLOAD(msg), 9);
#endif
}
