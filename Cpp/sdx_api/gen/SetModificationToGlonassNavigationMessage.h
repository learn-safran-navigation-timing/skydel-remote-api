#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetModificationToGlonassNavigationMessage is deprecated since 21.3. You may use SetMessageModificationToGlonassNav.
    /// 
    /// Set (or Modify) event to change navigation message bits.
    /// 
    /// Note that start and stop time are automatically extended to beginning and ending of overlapped
    /// message strings. The Modification parameter is a string where the first character applies to bit
    /// 85 of frame string and last character applies to Hamming Code bit 1.
    ///    '0' will force bit to zero
    ///    '1' will for bit to one
    ///    'X' will negate bit value
    ///    ' ' white space are ignored (use them to separate the string into bytes to help reading)
    ///    '-' or any other byte value will have no effect
    /// 
    /// Example:
    /// 
    /// "-0--- 1------- -------- -------- -------- -------- -------- -------- -------- -------- ---1--X-"
    ///   |  |                                           |  |
    ///   |  +- Force bit 80 to '1'               Force Hamming code bit 5 to '1' -+  |
    ///   |                                               |
    ///   +------ Force bit 84 to 0                   Negate Hamming code bit 2 ----+
    /// 
    /// Note: if UpdateHammingCode is true, any modification to bits 1..8 will have no effect.
    /// 
    /// The Id parameter is automatically updated with a unique id by the simulator for future reference.
    /// If the Id is set with a value other than an empty string, the simulator will try to find a match
    /// with previously added events. If there is a match, the event is updated with this message
    /// instead of adding a new event. If there is no match, the event is added and the id is not
    /// changed.
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

    class SetModificationToGlonassNavigationMessage;
    typedef std::shared_ptr<SetModificationToGlonassNavigationMessage> SetModificationToGlonassNavigationMessagePtr;
    
    
    class SetModificationToGlonassNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetModificationToGlonassNavigationMessage();

      SetModificationToGlonassNavigationMessage(int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id);
  
      static SetModificationToGlonassNavigationMessagePtr create(int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id);
      static SetModificationToGlonassNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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

