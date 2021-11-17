#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetModificationToGalileoINavMessage is deprecated since 21.3. You may use SetMessageModificationToGalileoINav.
    /// 
    /// Set (or Modify) event to change INAV message bits. If you send this command without setting the Id
    /// parameter, or if you set the Id with a value never used before, a new Modification event will be
    /// created. If you reuse the same event Id, it will modify the existing event.
    /// 
    /// Note that start and stop time are automatically extended to beginning and ending of overlapped
    /// messages.
    /// 
    /// BitsMods can be an empty string. The Modification will have no effect until you modify it with at
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
    /// You can add multiple bits mods using commas. For example: "24:X---10XX,127:100X,231:01"
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

    class SetModificationToGalileoINavMessage;
    typedef std::shared_ptr<SetModificationToGalileoINavMessage> SetModificationToGalileoINavMessagePtr;
    
    
    class SetModificationToGalileoINavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetModificationToGalileoINavMessage();

      SetModificationToGalileoINavMessage(int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id);
  
      static SetModificationToGalileoINavMessagePtr create(int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id);
      static SetModificationToGalileoINavMessagePtr dynamicCast(CommandBasePtr ptr);
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

