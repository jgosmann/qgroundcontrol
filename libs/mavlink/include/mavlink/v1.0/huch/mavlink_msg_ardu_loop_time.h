// MESSAGE ARDU_LOOP_TIME PACKING

#define MAVLINK_MSG_ID_ARDU_LOOP_TIME 233

typedef struct __mavlink_ardu_loop_time_t
{
 uint64_t usec; ///< microseconds
} mavlink_ardu_loop_time_t;

#define MAVLINK_MSG_ID_ARDU_LOOP_TIME_LEN 8
#define MAVLINK_MSG_ID_233_LEN 8



#define MAVLINK_MESSAGE_INFO_ARDU_LOOP_TIME { \
	"ARDU_LOOP_TIME", \
	1, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ardu_loop_time_t, usec) }, \
         } \
}


/**
 * @brief Pack a ardu_loop_time message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ardu_loop_time_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint64_t(buf, 0, usec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_ardu_loop_time_t packet;
	packet.usec = usec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_ARDU_LOOP_TIME;
	return mavlink_finalize_message(msg, system_id, component_id, 8, 104);
}

/**
 * @brief Pack a ardu_loop_time message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ardu_loop_time_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint64_t(buf, 0, usec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_ardu_loop_time_t packet;
	packet.usec = usec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_ARDU_LOOP_TIME;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 8, 104);
}

/**
 * @brief Encode a ardu_loop_time struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ardu_loop_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ardu_loop_time_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ardu_loop_time_t* ardu_loop_time)
{
	return mavlink_msg_ardu_loop_time_pack(system_id, component_id, msg, ardu_loop_time->usec);
}

/**
 * @brief Send a ardu_loop_time message
 * @param chan MAVLink channel to send the message
 *
 * @param usec microseconds
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ardu_loop_time_send(mavlink_channel_t chan, uint64_t usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint64_t(buf, 0, usec);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARDU_LOOP_TIME, buf, 8, 104);
#else
	mavlink_ardu_loop_time_t packet;
	packet.usec = usec;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARDU_LOOP_TIME, (const char *)&packet, 8, 104);
#endif
}

#endif

// MESSAGE ARDU_LOOP_TIME UNPACKING


/**
 * @brief Get field usec from ardu_loop_time message
 *
 * @return microseconds
 */
static inline uint64_t mavlink_msg_ardu_loop_time_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a ardu_loop_time message into a struct
 *
 * @param msg The message to decode
 * @param ardu_loop_time C-struct to decode the message contents into
 */
static inline void mavlink_msg_ardu_loop_time_decode(const mavlink_message_t* msg, mavlink_ardu_loop_time_t* ardu_loop_time)
{
#if MAVLINK_NEED_BYTE_SWAP
	ardu_loop_time->usec = mavlink_msg_ardu_loop_time_get_usec(msg);
#else
	memcpy(ardu_loop_time, _MAV_PAYLOAD(msg), 8);
#endif
}
