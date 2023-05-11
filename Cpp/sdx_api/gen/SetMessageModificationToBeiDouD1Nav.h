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
    /// Set (or Modify) event to change BeiDou D1 NAV navigation message bits.
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
    /// Note: if UpdateParity is true, any modification to parity bits will have no effect.
    /// 
    /// The ID parameter is automatically updated with a unique ID by the simulator for future reference.
    /// If the ID is set with a value other than an empty string, the simulator will try to find a match
    /// with previously added events. If there is a match, the event is updated with this message
    /// instead of adding a new event. If there is no match, the event is added and the ID is not
    /// changed.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ---------------------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "B1", "B2" and "B3I" (empty for all)
    /// SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)
    /// Page             int          Page 1..24 (use 0 to apply modification to all pages)
    /// Word             int          Word 1..10 (use 0 to apply modification to all words)
    /// UpdateParity     bool         Recalculate parity after making modification
    /// WordModification string       Modification string must be 30 bits long
    /// Id               string       Unique identifier of the event
    ///

    class SetMessageModificationToBeiDouD1Nav;
    typedef std::shared_ptr<SetMessageModificationToBeiDouD1Nav> SetMessageModificationToBeiDouD1NavPtr;
    
    
    class SetMessageModificationToBeiDouD1Nav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetMessageModificationToBeiDouD1Nav();

      SetMessageModificationToBeiDouD1Nav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);

      static SetMessageModificationToBeiDouD1NavPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);
      static SetMessageModificationToBeiDouD1NavPtr dynamicCast(CommandBasePtr ptr);
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


      // **** page ****
      int page() const;
      void setPage(int page);


      // **** word ****
      int word() const;
      void setWord(int word);


      // **** updateParity ****
      bool updateParity() const;
      void setUpdateParity(bool updateParity);


      // **** wordModification ****
      std::string wordModification() const;
      void setWordModification(const std::string& wordModification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

