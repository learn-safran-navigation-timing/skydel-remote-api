#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetModificationToQzssLNAVNavigationMessage is deprecated since 21.3. You may use SetMessageModificationToQzssLNav.
    /// 
    /// Set (or Modify) event to change navigation message bits.
    /// 
    /// Note that start and stop time are automatically extended to beginning and ending of overlapped
    /// subframes. The Modification parameter is a string where the first character applies to the first
    /// bit of subframe word and last character applies to last bit of subframe word.
    ///    '0' will force bit to zero
    ///    '1' will for bit to one
    ///    'X' will negate bit value
    ///    any other byte value will have no effect
    /// 
    /// Example: "-00------------------1-X------" will force bits 1 and 2 to zero and bit 22 to one
    ///                       and negate bit 24
    /// 
    /// Note: if UpdateParity is true, any modification to bits 25..30 will have no effect.
    /// 
    /// The Id parameter is automatically updated with a unique id by the simulator for future reference.
    /// If the ID is set with a value other than an empty string, the simulator will try to find a match
    /// with previously added events. If there is a match, the event is updated with this message
    /// instead of adding a new event. If there is no match, the event is added and the ID is not
    /// changed.
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

    class SetModificationToQzssLNAVNavigationMessage;
    typedef std::shared_ptr<SetModificationToQzssLNAVNavigationMessage> SetModificationToQzssLNAVNavigationMessagePtr;
    
    
    class SetModificationToQzssLNAVNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetModificationToQzssLNAVNavigationMessage();

      SetModificationToQzssLNAVNavigationMessage(int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id);
  
      static SetModificationToQzssLNAVNavigationMessagePtr create(int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id);
      static SetModificationToQzssLNAVNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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

