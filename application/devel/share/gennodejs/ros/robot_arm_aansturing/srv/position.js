// Auto-generated. Do not edit!

// (in-package robot_arm_aansturing.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class positionRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.angles = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0;
      }
      if (initObj.hasOwnProperty('angles')) {
        this.angles = initObj.angles
      }
      else {
        this.angles = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type positionRequest
    // Serialize message field [time]
    bufferOffset = _serializer.int32(obj.time, buffer, bufferOffset);
    // Serialize message field [angles]
    bufferOffset = _arraySerializer.int32(obj.angles, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type positionRequest
    let len;
    let data = new positionRequest(null);
    // Deserialize message field [time]
    data.time = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [angles]
    data.angles = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.angles.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'robot_arm_aansturing/positionRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '564bd91ce4bae241b82d4b8b931ce81e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 time
    int32[] angles
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new positionRequest(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0
    }

    if (msg.angles !== undefined) {
      resolved.angles = msg.angles;
    }
    else {
      resolved.angles = []
    }

    return resolved;
    }
};

class positionResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.accepted = null;
    }
    else {
      if (initObj.hasOwnProperty('accepted')) {
        this.accepted = initObj.accepted
      }
      else {
        this.accepted = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type positionResponse
    // Serialize message field [accepted]
    bufferOffset = _serializer.bool(obj.accepted, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type positionResponse
    let len;
    let data = new positionResponse(null);
    // Deserialize message field [accepted]
    data.accepted = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'robot_arm_aansturing/positionResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1ea39b897cc8620c46aaa14cb60920cd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool accepted
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new positionResponse(null);
    if (msg.accepted !== undefined) {
      resolved.accepted = msg.accepted;
    }
    else {
      resolved.accepted = false
    }

    return resolved;
    }
};

module.exports = {
  Request: positionRequest,
  Response: positionResponse,
  md5sum() { return 'f2b13f7d6d2e580339acb0496be6fd7a'; },
  datatype() { return 'robot_arm_aansturing/position'; }
};
