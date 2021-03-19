#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsMNavMessage
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------------------------------------------------
    /// Prn        int    Satellite PRN number 1..32
    /// StartTime  int    Elapsed time in seconds since start of simulation
    /// StopTime   int    Elapsed time in seconds since start of simulation
    /// MsgTypeId  int    MNAV Message type ID
    /// Occurrence int    Occurrence number in message sequence (1 based, or use -1 to match any occurrence)
    /// Condition  string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// BitsMods   string Comma separated bits mods
    /// Id         string Unique identifier automatically set by simulator
    ///

    class GetGpsMNavMessageResult;
    typedef std::shared_ptr<GetGpsMNavMessageResult> GetGpsMNavMessageResultPtr;
    
    
    class GetGpsMNavMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsMNavMessageResult();

      GetGpsMNavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, int occurrence, const std::string& condition, const std::string& bitsMods, const std::string& id);
  
      static GetGpsMNavMessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, int occurrence, const std::string& condition, const std::string& bitsMods, const std::string& id);
      static GetGpsMNavMessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** msgTypeId ****
      int msgTypeId() const;
      void setMsgTypeId(int msgTypeId);


      // **** occurrence ****
      int occurrence() const;
      void setOccurrence(int occurrence);


      // **** condition ****
      std::string condition() const;
      void setCondition(const std::string& condition);


      // **** bitsMods ****
      std::string bitsMods() const;
      void setBitsMods(const std::string& bitsMods);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

