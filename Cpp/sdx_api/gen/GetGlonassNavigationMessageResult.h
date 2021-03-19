#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassNavigationMessage
    ///
    /// Name              Type   Description
    /// ----------------- ------ -------------------------------------------------------------------------
    /// Prn               int    Satellite slot number number 1..24
    /// StartTime         int    Elapsed time in seconds since start of simulation
    /// StopTime          int    Elapsed time in seconds since start of simulation
    /// Frame             int    Frame 1..5 (use 0 to apply modification to all frames
    /// StringNumber      int    String 1..15 (use 0 to apply modification to all strings)
    /// UpdateHammingCode bool   Recalculate Hamming Code after making modification
    /// Modification      string Modification string must be 85 bytes long (or more if using white spaces)
    /// Id                string Unique identifier of the event
    ///

    class GetGlonassNavigationMessageResult;
    typedef std::shared_ptr<GetGlonassNavigationMessageResult> GetGlonassNavigationMessageResultPtr;
    
    
    class GetGlonassNavigationMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassNavigationMessageResult();

      GetGlonassNavigationMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id);
  
      static GetGlonassNavigationMessageResultPtr create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id);
      static GetGlonassNavigationMessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** frame ****
      int frame() const;
      void setFrame(int frame);


      // **** stringNumber ****
      int stringNumber() const;
      void setStringNumber(int stringNumber);


      // **** updateHammingCode ****
      bool updateHammingCode() const;
      void setUpdateHammingCode(bool updateHammingCode);


      // **** modification ****
      std::string modification() const;
      void setModification(const std::string& modification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

