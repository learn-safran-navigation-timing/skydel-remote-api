#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsCNav2Message
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..32
    /// StartTime int    Elapsed time in seconds since start of simulation
    /// StopTime  int    Elapsed time in seconds since start of simulation
    /// PageId    int    CNAV2 page ID
    /// Condition string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// UpdateCRC bool   Recalculate CRC after making modification
    /// BitsMods  string Comma separated bits mods
    /// Id        string Unique identifier of the event
    ///

    class GetGpsCNav2MessageResult;
    typedef std::shared_ptr<GetGpsCNav2MessageResult> GetGpsCNav2MessageResultPtr;
    
    
    class GetGpsCNav2MessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNav2MessageResult();

      GetGpsCNav2MessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int pageId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static GetGpsCNav2MessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int pageId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static GetGpsCNav2MessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** pageId ****
      int pageId() const;
      void setPageId(int pageId);


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

