#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoINavMessage
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..36 (use 0 to apply modification to all PRNs)
    /// StartTime int    Elapsed time in seconds since start of simulation
    /// StopTime  int    Elapsed time in seconds since start of simulation
    /// SubFrame  int    Subframe 1..24 (use 0 to apply modification to all subframes)
    /// Page      int    Page 1..15 (use 0 to apply modification to all pages)
    /// UpdateCRC bool   Recalculate CRC after making modification
    /// BitsMods  string Comma separated bits mods
    /// E1        bool   Apply modifications to Galileo E1 or not
    /// E5b       bool   Apply modifications to Galileo E1 or not
    /// Id        string Unique identifier of the event
    ///

    class GetGalileoINavMessageResult;
    typedef std::shared_ptr<GetGalileoINavMessageResult> GetGalileoINavMessageResultPtr;
    
    
    class GetGalileoINavMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoINavMessageResult();

      GetGalileoINavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id);
  
      static GetGalileoINavMessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id);
      static GetGalileoINavMessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** e1 ****
      bool e1() const;
      void setE1(bool e1);


      // **** e5b ****
      bool e5b() const;
      void setE5b(bool e5b);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

