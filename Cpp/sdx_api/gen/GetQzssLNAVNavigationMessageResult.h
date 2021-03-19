#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssLNAVNavigationMessage
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------------------------------------------------
    /// SvId            int    Satellite SV ID 1..10
    /// StartTime       int    Elapsed time in seconds since start of simulation
    /// StopTime        int    Elapsed time in seconds since start of simulation
    /// SubFrame        int    Subframe 1..5 (use 0 to apply modification to all subframes
    /// TransmittedSvId int    LNAV SV ID in subframe 4 and 5 (use 0 to apply modification to all SV ID)
    /// Word            int    Word 1..10 (use 0 to apply modification to all words)
    /// UpdateParity    bool   Recalculate parity after making modification
    /// Modification    string Modification string must be 30 bytes long
    /// Id              string Unique identifier of the event
    ///

    class GetQzssLNAVNavigationMessageResult;
    typedef std::shared_ptr<GetQzssLNAVNavigationMessageResult> GetQzssLNAVNavigationMessageResultPtr;
    
    
    class GetQzssLNAVNavigationMessageResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssLNAVNavigationMessageResult();

      GetQzssLNAVNavigationMessageResult(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id);
  
      static GetQzssLNAVNavigationMessageResultPtr create(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id);
      static GetQzssLNAVNavigationMessageResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** subFrame ****
      int subFrame() const;
      void setSubFrame(int subFrame);


      // **** transmittedSvId ****
      int transmittedSvId() const;
      void setTransmittedSvId(int transmittedSvId);


      // **** word ****
      int word() const;
      void setWord(int word);


      // **** updateParity ****
      bool updateParity() const;
      void setUpdateParity(bool updateParity);


      // **** modification ****
      std::string modification() const;
      void setModification(const std::string& modification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

