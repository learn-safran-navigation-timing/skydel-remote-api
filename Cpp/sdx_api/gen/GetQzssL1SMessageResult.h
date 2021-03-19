#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL1SMessage
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------
    /// SvId        int    Satellite SV ID 1..10
    /// StartTime   int    Elapsed time in seconds since start of simulation
    /// StopTime    int    Elapsed time in seconds since start of simulation
    /// MessageType int    L1S Message type ID
    /// Condition   string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// UpdateCRC   bool   Recalculate CRC after making modification
    /// BitsMods    string Comma separated bits mods
    /// Id          string Unique identifier of the event
    ///

    class GetQzssL1SMessageResult;
    typedef std::shared_ptr<GetQzssL1SMessageResult> GetQzssL1SMessageResultPtr;
    
    
    class GetQzssL1SMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1SMessageResult();

      GetQzssL1SMessageResult(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static GetQzssL1SMessageResultPtr create(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static GetQzssL1SMessageResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


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

