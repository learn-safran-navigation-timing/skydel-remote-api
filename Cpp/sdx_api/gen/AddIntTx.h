#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set an interference transmitter. If the transmitter ID parameter is not set (empty string),
    /// Skydel will assign a unique ID to the transmitter. If the ID is set and already used by Skydel, the
    /// command will fail.
    ///
    /// Name      Type   Description
    /// --------- ------ ----------------------------------------------------------------------------------------
    /// UsualName string Usual name for the transmitter.
    /// Enabled   bool   Enable (true) or disable (false) the transmitter
    /// Group     int    Interference group number [1..16]
    /// Dynamic   bool   Set to true for a dynamic transmitter (propagation loss and doppler shift are simulated)
    /// Power     double Set the transmitter reference power
    /// Id        string Transmitter unique identifier.
    ///

    class AddIntTx;
    typedef std::shared_ptr<AddIntTx> AddIntTxPtr;
    
    
    class AddIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      AddIntTx();

      AddIntTx(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id);

      static AddIntTxPtr create(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id);
      static AddIntTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** usualName ****
      std::string usualName() const;
      void setUsualName(const std::string& usualName);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** group ****
      int group() const;
      void setGroup(int group);


      // **** dynamic ****
      bool dynamic() const;
      void setDynamic(bool dynamic);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

