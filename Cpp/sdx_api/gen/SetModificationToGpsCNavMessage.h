#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetModificationToGpsCNavMessage is deprecated since 21.3. You may use SetMessageModificationToGpsCNav.
    /// 
    /// Set (or Modify) event to change CNAV message bits. If you send this command without setting the Id
    /// parameter, or if you set the Id with a value never used before, a new Modification event will be
    /// created. If you reuse the same event Id, it will modify the existing event.
    /// 
    /// Note that start and stop time are automatically extended to beginning and ending of overlapped
    /// messages.
    /// 
    /// The Condition parameter is optional and allows you to add content matching condition before applying
    /// bits mods.
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
    /// Prn       int    Satellite PRN number 1..32
    /// StartTime int    Elapsed time in seconds since start of simulation
    /// StopTime  int    Elapsed time in seconds since start of simulation
    /// MsgTypeId int    CNAV Message type ID
    /// Condition string Optional condition to match message content, ex: "EQUAL(45,10,0x3F)"
    /// UpdateCRC bool   Recalculate CRC after making modification
    /// BitsMods  string Comma separated bits mods
    /// Id        string Unique identifier of the event
    ///

    class SetModificationToGpsCNavMessage;
    typedef std::shared_ptr<SetModificationToGpsCNavMessage> SetModificationToGpsCNavMessagePtr;
    
    
    class SetModificationToGpsCNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetModificationToGpsCNavMessage();

      SetModificationToGpsCNavMessage(int prn, int startTime, int stopTime, int msgTypeId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
  
      static SetModificationToGpsCNavMessagePtr create(int prn, int startTime, int stopTime, int msgTypeId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id);
      static SetModificationToGpsCNavMessagePtr dynamicCast(CommandBasePtr ptr);
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


      // **** msgTypeId ****
      int msgTypeId() const;
      void setMsgTypeId(int msgTypeId);


      // **** condition ****
      std::string condition() const;
      void setCondition(const std::string& condition);


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

