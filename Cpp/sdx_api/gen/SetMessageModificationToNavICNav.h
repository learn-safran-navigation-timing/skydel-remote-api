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
    /// Set (or Modify) event to change NavIC NAV message bits. If you send this command without setting the ID
    /// parameter, or if you set the ID with a value never used before, a new Modification event will be
    /// created. If you reuse the same event ID, it will modify the existing event.
    /// 
    /// Note that start and stop time are automatically extended to beginning and ending of overlapped
    /// messages.
    /// 
    /// The Condition parameter is optional and allows you to add content matching condition before applying
    /// bit modifications.
    /// 
    /// BitModifications can be an empty string. The Modification will have no effect until you modify it with at
    /// least one bits mod.
    /// 
    /// A bits mod is represented with a string using the following format: "I:Bits" where I is a bit
    /// index (1 refers to the first transmitted bit) and Bits is a modification mask where each
    /// character describes a modification to a single bit. The allowed characters are:
    ///    0 : force bit to 0
    ///    1 : force bit to 1
    ///    - : leave bit unchanged
    ///    X : revert bit (0 becomes 1 and 1 becomes 0)
    /// 
    /// For example: "24:X---10XX" will: revert bits 24, 30 and 31
    ///                  set bit 28 to 1
    ///                  set bit 29 to 0
    /// The other bits are not affected.
    /// 
    /// You can add multiple bit modifications using commas. For example: "24:X---10XX,127:100X,231:01"
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ----------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "NAVICL5" (empty for all)
    /// SvId             int          The satellite's SV ID 1..14 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Subframe         int          Subframe 1..4 (use 0 to apply modification to all subframes)
    /// MessageType      int          NAV Message type (use -1 to apply modification to all message types)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// UpdateCRC        bool         Recalculate CRC after making modification
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class SetMessageModificationToNavICNav;
    typedef std::shared_ptr<SetMessageModificationToNavICNav> SetMessageModificationToNavICNavPtr;
    
    
    class SetMessageModificationToNavICNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetMessageModificationToNavICNav();

      SetMessageModificationToNavICNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static SetMessageModificationToNavICNavPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);
      static SetMessageModificationToNavICNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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


      // **** subframe ****
      int subframe() const;
      void setSubframe(int subframe);


      // **** messageType ****
      int messageType() const;
      void setMessageType(int messageType);


      // **** condition ****
      std::string condition() const;
      void setCondition(const std::string& condition);


      // **** updateCRC ****
      bool updateCRC() const;
      void setUpdateCRC(bool updateCRC);


      // **** bitModifications ****
      std::string bitModifications() const;
      void setBitModifications(const std::string& bitModifications);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

