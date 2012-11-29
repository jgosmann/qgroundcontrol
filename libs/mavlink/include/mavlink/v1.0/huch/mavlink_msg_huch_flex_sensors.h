// MESSAGE HUCH_FLEX_SENSORS PACKING

#define MAVLINK_MSG_ID_HUCH_FLEX_SENSORS 232

typedef struct __mavlink_huch_flex_sensors_t
{
 uint64_t usec; ///< timestamp in microseconds
 uint16_t front; ///< Front sensor value
 uint16_t left; ///< Left sensor value
 uint16_t back; ///< Back sensor value
 uint16_t right; ///< Right sensor value
} mavlink_huch_flex_sensors_t;

#define MAVLINK_MSG_ID_HUCH_FLEX_SENSORS_LEN 16
#define MAVLINK_MSG_ID_232_LEN 16



#define MAVLINK_MESSAGE_INFO_HUCH_FLEX_SENSORS { \
	"HUCH_FLEX_SENSORS", \
	5, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_huch_flex_sensors_t, usec) }, \
         { "front", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_huch_flex_sensors_t, front) }, \
         { "left", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_huch_flex_sensors_t, left) }, \
         { "back", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_huch_flex_sensors_t, back) }, \
         { "right", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_huch_flex_sensors_t, right) }, \
         } \
}


/**
 * @brief Pack a huch_flex_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec timestamp in microseconds
 * @param front Front sensor value
 * @param left Left sensor value
 * @param back Back sensor value
 * @param right Right sensor value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, uint16_t front, uint16_t left, uint16_t back, uint16_t right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[16];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint16_t(buf, 8, front);
	_mav_put_uint16_t(buf, 10, left);
	_mav_put_uint16_t(buf, 12, back);
	_mav_put_uint16_t(buf, 14, right);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 16);
#else
	mavlink_huch_flex_sensors_t packet;
	packet.usec = usec;
	packet.front = front;
	packet.left = left;
	packet.back = back;
	packet.right = right;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 16);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_FLEX_SENSORS;
	return mavlink_finalize_message(msg, system_id, component_id, 16, 197);
}

/**
 * @brief Pack a huch_flex_sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec timestamp in microseconds
 * @param front Front sensor value
 * @param left Left sensor value
 * @param back Back sensor value
 * @param right Right sensor value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint16_t front,uint16_t left,uint16_t back,uint16_t right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[16];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint16_t(buf, 8, front);
	_mav_put_uint16_t(buf, 10, left);
	_mav_put_uint16_t(buf, 12, back);
	_mav_put_uint16_t(buf, 14, right);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 16);
#else
	mavlink_huch_flex_sensors_t packet;
	packet.usec = usec;
	packet.front = front;
	packet.left = left;
	packet.back = back;
	packet.right = right;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 16);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_FLEX_SENSORS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 16, 197);
}

/**
 * @brief Encode a huch_flex_sensors struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_flex_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_flex_sensors_t* huch_flex_sensors)
{
	return mavlink_msg_huch_flex_sensors_pack(system_id, component_id, msg, huch_flex_sensors->usec, huch_flex_sensors->front, huch_flex_sensors->left, huch_flex_sensors->back, huch_flex_sensors->right);
}

/**
 * @brief Send a huch_flex_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param usec timestamp in microseconds
 * @param front Front sensor value
 * @param left Left sensor value
 * @param back Back sensor value
 * @param right Right sensor value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_flex_sensors_send(mavlink_channel_t chan, uint64_t usec, uint16_t front, uint16_t left, uint16_t back, uint16_t right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[16];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_uint16_t(buf, 8, front);
	_mav_put_uint16_t(buf, 10, left);
	_mav_put_uint16_t(buf, 12, back);
	_mav_put_uint16_t(buf, 14, right);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_FLEX_SENSORS, buf, 16, 197);
#else
	mavlink_huch_flex_sensors_t packet;
	packet.usec = usec;
	packet.front = front;
	packet.left = left;
	packet.back = back;
	packet.right = right;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_FLEX_SENSORS, (const char *)&packet, 16, 197);
#endif
}

#endif

// MESSAGE HUCH_FLEX_SENSORS UNPACKING


/**
 * @brief Get field usec from huch_flex_sensors message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_flex_sensors_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field front from huch_flex_sensors message
 *
 * @return Front sensor value
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_get_front(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field left from huch_flex_sensors message
 *
 * @return Left sensor value
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_get_left(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field back from huch_flex_sensors message
 *
 * @return Back sensor value
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_get_back(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field right from huch_flex_sensors message
 *
 * @return Right sensor value
 */
static inline uint16_t mavlink_msg_huch_flex_sensors_get_right(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Decode a huch_flex_sensors message into a struct
 *
 * @param msg The message to decode
 * @param huch_flex_sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_flex_sensors_decode(const mavlink_message_t* msg, mavlink_huch_flex_sensors_t* huch_flex_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP
	huch_flex_sensors->usec = mavlink_msg_huch_flex_sensors_get_usec(msg);
	huch_flex_sensors->front = mavlink_msg_huch_flex_sensors_get_front(msg);
	huch_flex_sensors->left = mavlink_msg_huch_flex_sensors_get_left(msg);
	huch_flex_sensors->back = mavlink_msg_huch_flex_sensors_get_back(msg);
	huch_flex_sensors->right = mavlink_msg_huch_flex_sensors_get_right(msg);
#else
	memcpy(huch_flex_sensors, _MAV_PAYLOAD(msg), 16);
#endif
}
