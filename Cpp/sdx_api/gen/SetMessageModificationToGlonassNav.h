#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set (or Modify) event to change GLONASS NAV message bits.
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
    /// The ID parameter is automatically updated with a unique ID by the simulator for future reference.
    /// If the ID is set with a value other than an empty string, the simulator will try to find a match
    /// with previously added events. If there is a match, the event is updated with this message
    /// instead of adding a new event. If there is no match, the event is added and the ID is not
    /// changed.
    ///
    /// Name               Type         Description
    /// ------------------ ------------ --------------------------------------------------------------------------------------------
    /// SignalArray        array string Array of signals to apply the message modification to, accepts "G1" and "G2" (empty for all)
    /// SvId               int          The satellite's SV ID number 1..24 (use 0 to apply modification to all SVs)
    /// StartTime          int          Elapsed time in seconds since start of simulation
    /// StopTime           int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Frame              int          Frame 1..5 (use 0 to apply modification to all frames)
    /// StringNumber       int          String 1..15 (use 0 to apply modification to all strings)
    /// UpdateHammingCode  bool         Recalculate Hamming Code after making modification
    /// StringModification string       Modification string must be 85 bits long (or more if using white spaces)
    /// Id                 string       Unique identifier of the event
    ///

    class SetMessageModificationToGlonassNav;
    typedef std::shared_ptr<SetMessageModificationToGlonassNav> SetMessageModificationToGlonassNavPtr;
    
    
    class SetMessageModificationToGlonassNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetMessageModificationToGlonassNav();

      SetMessageModificationToGlonassNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id);

      static SetMessageModificationToGlonassNavPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id);
      static SetMessageModificationToGlonassNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signalArray ****
      std::vector<std::string> signalArray() const;
      void setSignalArray(const std::vector<std::string>& signalArray);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


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


      // **** stringModification ****
      std::string stringModification() const;
      void setStringModification(const std::string& stringModification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

