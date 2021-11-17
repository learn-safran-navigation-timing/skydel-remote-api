#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoFNavMessage.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..36 (use 0 to apply modification to all PRNs)
    /// StartTime int    Elapsed time in seconds since start of simulation
    /// StopTime  int    Elapsed time in seconds since start of simulation
    /// SubFrame  int    Subframe 1..12 (use 0 to apply modification to all subframes)
    /// Page      int    Page 1..5 (use 0 to apply modification to all pages)
    /// UpdateCRC bool   Recalculate CRC after making modification
    /// BitsMods  string Comma separated bits mods
    /// Id        string Unique identifier of the event
    ///

    class GetGalileoFNavMessageResult;
    typedef std::shared_ptr<GetGalileoFNavMessageResult> GetGalileoFNavMessageResultPtr;
    
    
    class GetGalileoFNavMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoFNavMessageResult();

      GetGalileoFNavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static GetGalileoFNavMessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static GetGalileoFNavMessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** subFrame ****
      int subFrame() const;
      void setSubFrame(int subFrame);


      // **** page ****
      int page() const;
      void setPage(int page);


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

