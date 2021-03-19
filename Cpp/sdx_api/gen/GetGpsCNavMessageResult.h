#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsCNavMessage
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..32
    /// StartTime int    Elapsed time in seconds since start of simulation
    /// StopTime  int    Elapsed time in seconds since start of simulation
    /// MsgTypeId int    CNAV Message type ID
    /// Condition string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// UpdateCRC bool   Recalculate CRC after making modification
    /// BitsMods  string Comma separated bits mods
    /// Id        string Unique identifier of the event
    ///

    class GetGpsCNavMessageResult;
    typedef std::shared_ptr<GetGpsCNavMessageResult> GetGpsCNavMessageResultPtr;
    
    
    class GetGpsCNavMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNavMessageResult();

      GetGpsCNavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static GetGpsCNavMessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static GetGpsCNavMessageResultPtr dynamicCast(CommandBasePtr ptr);
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

