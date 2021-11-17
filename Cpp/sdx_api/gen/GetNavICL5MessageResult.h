#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICL5Message.
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------
    /// SvId        int    Satellite SV ID number 1..14
    /// StartTime   int    Elapsed time in seconds since start of simulation
    /// StopTime    int    Elapsed time in seconds since start of simulation
    /// Subframe    int    Subframe 1..5
    /// MessageType int    Nav Message type
    /// Condition   string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// UpdateCRC   bool   Recalculate CRC after making modification
    /// BitsMods    string Comma separated bits mods
    /// Id          string Unique identifier of the event
    ///

    class GetNavICL5MessageResult;
    typedef std::shared_ptr<GetNavICL5MessageResult> GetNavICL5MessageResultPtr;
    
    
    class GetNavICL5MessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICL5MessageResult();

      GetNavICL5MessageResult(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static GetNavICL5MessageResultPtr create(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static GetNavICL5MessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** subframe ****
      int subframe() const;
      void setSubframe(int subframe);


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

