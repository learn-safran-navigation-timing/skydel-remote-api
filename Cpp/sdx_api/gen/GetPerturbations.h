#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID.
    ///

    class GetPerturbations;
    typedef std::shared_ptr<GetPerturbations> GetPerturbationsPtr;
    
    
    class GetPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPerturbations();

      GetPerturbations(const std::string& system, int svId);
  
      static GetPerturbationsPtr create(const std::string& system, int svId);
      static GetPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

