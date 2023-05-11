#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) P(Y)-Code for specified satellite.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------
    /// Signal  string Accepted signal keys: "L1P", "L2P"
    /// SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)
    /// Enabled bool   Enable P(Y)-Code if True
    ///

    class EnablePYCodeForSV;
    typedef std::shared_ptr<EnablePYCodeForSV> EnablePYCodeForSVPtr;
    
    
    class EnablePYCodeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnablePYCodeForSV();

      EnablePYCodeForSV(const std::string& signal, int svId, bool enabled);

      static EnablePYCodeForSVPtr create(const std::string& signal, int svId, bool enabled);
      static EnablePYCodeForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

