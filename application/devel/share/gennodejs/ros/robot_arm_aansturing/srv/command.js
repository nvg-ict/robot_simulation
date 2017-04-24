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

class commandRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.command = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0;
      }
      if (initObj.hasOwnProperty('command')) {
        this.command = initObj.command
      }
      else {
        this.command = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type commandRequest
    // Serialize message field [time]
    bufferOffset = _serializer.int32(obj.time, buffer, bufferOffset);
    // Serialize message field [command]
    bufferOffset = _serializer.string(obj.command, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type commandRequest
    let len;
    let data = new commandRequest(null);
    // Deserialize message field [time]
    data.time = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [command]
    data.command = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.command.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'robot_arm_aansturing/commandRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e910f6b13df2ebbf25f3d3309811088e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 time
    string command
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new commandRequest(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0
    }

    if (msg.command !== undefined) {
      resolved.command = msg.command;
    }
    else {
      resolved.command = ''
    }

    return resolved;
    }
};

class commandResponse {
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
    // Serializes a message object of type commandResponse
    // Serialize message field [accepted]
    bufferOffset = _serializer.bool(obj.accepted, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type commandResponse
    let len;
    let data = new commandResponse(null);
    // Deserialize message field [accepted]
    data.accepted = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'robot_arm_aansturing/commandResponse';
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
    const resolved = new commandResponse(null);
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
  Request: commandRequest,
  Response: commandResponse,
  md5sum() { return 'ff0e3fb9acee100884c63efa5d599c72'; },
  datatype() { return 'robot_arm_aansturing/command'; }
};
