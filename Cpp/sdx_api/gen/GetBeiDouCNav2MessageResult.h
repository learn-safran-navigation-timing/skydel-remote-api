#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouCNav2Message
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------
    /// Prn         int    Satellite PRN number 1..30
    /// StartTime   int    Elapsed time in seconds since start of simulation
    /// StopTime    int    Elapsed time in seconds since start of simulation
    /// MessageType int    CNAV2 Message Type
    /// Condition   string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// UpdateCRC   bool   Recalculate CRC after making modification
    /// BitsMods    string Comma separated bits mods
    /// Id          string Unique identifier of the event
    ///

    class GetBeiDouCNav2MessageResult;
    typedef std::shared_ptr<GetBeiDouCNav2MessageResult> GetBeiDouCNav2MessageResultPtr;
    
    
    class GetBeiDouCNav2MessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav2MessageResult();

      GetBeiDouCNav2MessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static GetBeiDouCNav2MessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static GetBeiDouCNav2MessageResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** startTime ****
      int startTime() const;
      void setStartTime(int startTime);


      // **** stopTime ****
      int stopTime() const;
      void setStopTime(int stopTime);


      // **** messageType ****
      int messageType() const;
      void setMessageType(int messageType);


      // **** condition ****
      std::string condition() const;
      void setCondition(const std::string& condition);


      // **** updateCRC ****
      bool updateCRC() const;
      void setUpdateCRC(bool updateCRC);


      // **** bitsMods ****
      std::string bitsMods() const;
      void setBitsMods(const std::string& bitsMods);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

